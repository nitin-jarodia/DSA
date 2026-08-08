class DiningPhilosophers {
private:
    mutex fork[5];

public:
    DiningPhilosophers() {}

    void wantsToEat(
        int philosopher,
        function<void()> pickLeftFork,
        function<void()> pickRightFork,
        function<void()> eat,
        function<void()> putLeftFork,
        function<void()> putRightFork) {

        int left = philosopher;
        int right = (philosopher + 1) % 5;

        if (philosopher % 2 == 0) {

            lock_guard<mutex> l(fork[left]);
            lock_guard<mutex> r(fork[right]);

            pickLeftFork();
            pickRightFork();

            eat();

            putRightFork();
            putLeftFork();
        }
        else {

            lock_guard<mutex> r(fork[right]);
            lock_guard<mutex> l(fork[left]);

            pickRightFork();
            pickLeftFork();

            eat();

            putLeftFork();
            putRightFork();
        }
    }
};