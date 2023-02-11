import java.util.logging.*;

public class LoggingAdapter implements CustomeLogger{

    private Logger logger;
    private Level level;

    public LoggingAdapter(String name, Level level)
    {
        this.logger = Logger.getLogger(name);
        this.level = level;
    }

    @Override
    public void log(String message) {
        if(level == Level.SEVERE)
            logger.severe(message);
        else if(level == Level.WARNING)
            logger.severe(message);
        else if(level == Level.INFO)
            logger.severe(message);
        else if(level == Level.FINER)
            logger.severe(message);
    }
}