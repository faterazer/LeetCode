class Solution:
    def countMentions(self, numberOfUsers: int, events: list[list[str]]) -> list[int]:
        events.sort(key=lambda x: (int(x[1]), x[0] == "MESSAGE"))
        result = [0] * numberOfUsers
        online_t = [0] * numberOfUsers
        all_cnt = 0
        for event_type, timestamp, mention in events:
            timestamp = int(timestamp)
            if event_type == "MESSAGE":
                if mention == "ALL":
                    all_cnt += 1
                elif mention == "HERE":
                    for i in range(numberOfUsers):
                        if online_t[i] <= timestamp:
                            result[i] += 1
                else:
                    for part in mention.split():
                        result[int(part[2:])] += 1
            else:
                online_t[int(mention)] = timestamp + 60
        return [t + all_cnt for t in result]
