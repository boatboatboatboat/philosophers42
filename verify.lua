--
-- Created by IntelliJ IDEA.
-- User: boat
-- Date: 12-06-20
-- Time: 11:52
-- To change this template use File | Settings | File Templates.
--

local function printf(...)
    print(string.format(...))
end

local last_exec = {};

local forks = tonumber(arg[2]);
print("Forks:", forks)

local death_time = tonumber(arg[3]);
local eat_time = tonumber(arg[4]);
local sleep_time = tonumber(arg[5]);

local base_matcher = "(%d+) (%d+) "
local matchers = {
    thinking = "is thinking",
    take_fork = "has taken a fork",
    eating = "is eating",
    sleeping = "is sleeping",
    died = "died",
}

local prog = io.popen(table.concat(arg, ' '));
local sim_stopped = false;

for line in prog:lines() do
    if sim_stopped then
        printf("\x1b[31mSimulation should have stopped, yet another line was printed\x1b[0m");
        printf("%s", line);
        printf("Exiting...")
        os.exit(0);
    end

    local matched = false;
    local stamp, id;

    for state, matchstring in pairs(matchers) do
        stamp, id = line:match(base_matcher .. matchstring);

        if stamp and id then
            stamp, id = tonumber(stamp), tonumber(id);
            local last_state = last_exec[id];

            if state == "died" then
                sim_stopped = true;
                matched = true;
                break;
            end

            if last_state then
                if (stamp - last_state.last_meal) > death_time then
                    printf("\x1b[31m%d should be dead. Death time: %d, Difference: %d\x1b[0m",
                        id,
                        last_state.last_meal + death_time,
                        stamp - last_state.last_meal - death_time)
                end

                if last_state.state == "thinking" then
                    if state == "take_fork" then
                        forks = forks - 1;
                        if forks < 0 then
                            printf("\x1b[33m%d picked up a non-existant fork\x1b[0m", id);
                            print(line);
                        end
                    else
                        printf("%d performed an invalid state switch: thinking -> %s", id, state);
                        os.exit(0);
                    end
                elseif last_state.state == "take_fork" then
                    if state == "eating" then
                        forks = forks - 1;
                        if forks < 0 then
                            printf("\x1b[33m%d picked up a non-existant fork\x1b[0m", id);
                        end
                        last_state.last_meal = stamp;
                    else
                        printf("%d performed an invalid state switch: take_fork -> %s", state);
                        os.exit(0);
                    end
                elseif last_state.state == "eating" then
                    if state == "sleeping" then
                        if (stamp - last_state.stamp) > eat_time then
                            printf(
                                "\x1b[33m%d eat time differs. Real time: %d, Expected time: %d\x1b[0m",
                                id, stamp - last_state.stamp, eat_time);
                        end
                        forks = forks + 2;
                    else
                        printf("%d performed an invalid state switch: eating -> %s", state);
                        os.exit(0);
                    end
                elseif last_state.state == "sleeping" then
                    if state == "thinking" then
                        if (stamp - last_state.stamp) ~= sleep_time then
                            printf(
                                "\x1b[33m%d sleep time differs. Real time: %d, Expected time: %d\x1b[0m",
                                id, stamp - last_state.stamp, sleep_time);
                        end
                    else
                        printf("%d performed an invalid state switch: sleeping -> %s", state);
                        os.exit(0)
                    end
                end
                last_state.stamp = stamp;
                last_state.state = state;
            else
                last_exec[id] = { stamp = stamp, state = state, last_meal = stamp };
            end
            matched = true;
            break ;
        end
    end

    if not matched then
        printf("Found invalid string: \"%s\"", line);
        os.exit(0);
    end

    printf(line)
end
