
class Singleton
{
    private static Singleton single_instance = null;
    public String s;

    private Singleton()
    {
        s= "In side constructor";
    }

    public static Singleton GetInstance()
    {
        if(single_instance == null){
            System.out.println("Inside static function if block");
            single_instance = new Singleton();
        }

        return single_instance;
    }
}

