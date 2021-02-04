class Foo {
    Semaphore firstDone = new Semaphore(0);
    Semaphore secondDone = new Semaphore(0);

    public Foo() {}

    public void first(Runnable printFirst) throws InterruptedException {
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        firstDone.release();
    }

    public void second(Runnable printSecond) throws InterruptedException {
        firstDone.acquire();
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        secondDone.release();
    }

    public void third(Runnable printThird) throws InterruptedException {
        secondDone.acquire();
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
    }
}
