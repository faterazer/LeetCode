import threading
from typing import Callable


class Foo:
    def __init__(self):
        self.firstDone = threading.Lock()
        self.firstDone.acquire()
        self.secondDone = threading.Lock()
        self.secondDone.acquire()

    def first(self, printFirst: Callable[[], None]) -> None:
        # printFirst() outputs "first". Do not change or remove this line.
        printFirst()
        self.firstDone.release()

    def second(self, printSecond: Callable[[], None]) -> None:
        with self.firstDone:
            # printSecond() outputs "second". Do not change or remove this line.
            printSecond()
            self.secondDone.release()

    def third(self, printThird: Callable[[], None]) -> None:
        with self.secondDone:
            # printThird() outputs "third". Do not change or remove this line.
            printThird()
