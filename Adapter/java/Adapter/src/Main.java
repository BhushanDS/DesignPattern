import java.util.logging.Level;

public class Main {
    public static void main(String[] args) {
        CustomeLogger logger = new LoggingAdapter("my_logger", Level.WARNING);
        logger.log("Warning Raise");
    }
}