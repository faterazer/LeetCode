class Solution:
    def interpret_MK1(self, command: str) -> str:
        return command.replace('()', 'o').replace('(al)', 'al')

    def interpret_MK2(self, command: str) -> str:
        res = []
        for i, c in enumerate(command):
            if c == 'G':
                res.append('G')
            elif c == ')':
                if command[i - 1] == '(':
                    res.append('o')
                else:
                    res.append('al')
        return ''.join(res)
