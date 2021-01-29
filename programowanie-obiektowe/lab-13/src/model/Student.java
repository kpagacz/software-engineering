package model;

public class Student extends Person{
    private String major;

    public Student(String name, String surname, String major) {
        super(name, surname);
        this.major = major;
    }

    @Override
    public String toString() {
        return super.toString() + ", major: " + major;
    }
}



