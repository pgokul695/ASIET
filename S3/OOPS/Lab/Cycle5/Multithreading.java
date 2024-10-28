import java.util.*;

class thread1 implements Runnable {
    public void run() {
        int n = (int) (Math.random() * 100);
        System.out.println("The generated number is " + n);
        if (n % 2 == 0) {
            thread2 even = new thread2(n);
            Thread evenThread = new Thread(even);
            evenThread.start();
        } else {
            thread3 odd = new thread3(n);
            Thread oddThread = new Thread(odd);
            oddThread.start();
        }
    }
}

class thread2 implements Runnable {
    private int number;

    thread2(int n) {
        number = n;
    }

    public void run() {
        System.out.println("The square of the number is " + (number * number));
    }
}

class thread3 implements Runnable {
    private int number;

    thread3(int n) {
        number = n;
    }

    public void run() {
        System.out.println("The cube of the number is " + (number * number * number));
    }
}

class main {
    public static void main(String[] args) {
        thread1 t = new thread1();
        Thread thread = new Thread(t);
        thread.start();
    }
}

