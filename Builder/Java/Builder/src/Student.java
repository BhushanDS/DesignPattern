//Server Side Code

final class Student{
    private final int id;
    private final String name;
    private final String address;

    public Student(Builder builder) {
        this.id = builder.getId();
        this.name = builder.getName();
        this.address = builder.getAddress();
    }

}