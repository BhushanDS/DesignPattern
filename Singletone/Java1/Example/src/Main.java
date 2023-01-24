

public class Main {
    public static void main(String[] args) {
        Singleton s = Singleton.GetInstance();
        Singleton m = Singleton.GetInstance();
        Singleton n = Singleton.GetInstance();
    }
}