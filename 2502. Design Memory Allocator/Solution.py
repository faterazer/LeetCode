from collections import defaultdict


class Allocator:

    def __init__(self, n: int):
        self.mem_table = {0: n}
        self.id2blocks = defaultdict(list)

    def allocate(self, size: int, mID: int) -> int:
        beg_addr = -1
        addrs = sorted(self.mem_table.keys())
        for addr in addrs:
            if self.mem_table[addr] >= size:
                beg_addr = addr
                break
        if beg_addr == -1:
            return -1
        self.id2blocks[mID].append((beg_addr, size))
        if self.mem_table[beg_addr] > size:
            self.mem_table[beg_addr + size] = self.mem_table[beg_addr] - size
        self.mem_table.pop(beg_addr)
        return beg_addr

    def freeMemory(self, mID: int) -> int:
        if mID not in self.id2blocks:
            return 0
        blocks = self.id2blocks.pop(mID)
        ans = 0
        for addr, blk_size in blocks:
            ans += blk_size
            self.mem_table[addr] = blk_size

        del_addrs = set()
        addrs = sorted(self.mem_table.keys())
        for addr in addrs:
            while addr not in del_addrs and addr + self.mem_table[addr] in self.mem_table:
                del_addrs.add(addr + self.mem_table[addr])
                self.mem_table[addr] += self.mem_table[addr + self.mem_table[addr]]
        for addr in del_addrs:
            self.mem_table.pop(addr)
        return ans


# Your Allocator object will be instantiated and called as such:
# obj = Allocator(n)
# param_1 = obj.allocate(size,mID)
# param_2 = obj.freeMemory(mID)
