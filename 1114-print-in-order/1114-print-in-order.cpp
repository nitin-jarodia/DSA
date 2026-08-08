class Foo {
private:
    mutex mtx;
    condition_variable cv;
    int turn;

public:
    Foo() {
        turn = 1;
    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> lock(mtx);

        printFirst();
        turn = 2;

        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(mtx);

        cv.wait(lock, [&]() {
            return turn == 2;
        });

        printSecond();
        turn = 3;

        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(mtx);

        cv.wait(lock, [&]() {
            return turn == 3;
        });

        printThird();
    }
};