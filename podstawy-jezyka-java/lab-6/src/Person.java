import java.time.*;
import java.time.format.TextStyle;
import java.util.Locale;

public class Person {
    private String name, surname;
    private LocalDate birthDate;
    private LocalTime timeOfBirth;
    public static enum Gender {MALE, FEMALE};

    public Person(String name, String surname, LocalDate birthDate, LocalTime timeOfBirth) {
        this.name = name;
        this.surname = surname;
        this.birthDate = birthDate;
        this.timeOfBirth = timeOfBirth;
    }

    public Person(String name, String surname, String birthDate, String timeOfBirth) {
        this.name = name;
        this.surname = surname;
        this.birthDate = LocalDate.parse(birthDate);
        this.timeOfBirth = LocalTime.parse(timeOfBirth);
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public String getSurname() {
        return surname;
    }

    public void setBirthDate(LocalDate birthDate) {
        this.birthDate = birthDate;
    }

    public LocalDate getBirthDate() {
        return birthDate;
    }

    public LocalTime getTimeOfBirth() {
        return timeOfBirth;
    }

    public void setTimeOfBirth(LocalTime timeOfBirth) {
        this.timeOfBirth = timeOfBirth;
    }

    public Gender getGender() {
        if (name.charAt(name.length() - 1) == 'a'){
            return Gender.FEMALE;
        } else {
            return Gender.MALE;
        }
    }

    public int getAge() {
        return Period.between(birthDate, LocalDate.now()).getYears();
    }

    public String getDayOfBirth() {
        return birthDate.getDayOfWeek().getDisplayName(TextStyle.FULL_STANDALONE, Locale.getDefault());
    }

    public void reverseNameAndSurname() {
        StringBuilder nameBuilder = new StringBuilder(name.toLowerCase());
        nameBuilder.reverse();
        nameBuilder.replace(0, 1, nameBuilder.substring(0, 1).toUpperCase());

        StringBuilder surnameBuilder = new StringBuilder(surname.toLowerCase());
        surnameBuilder.reverse();
        surnameBuilder.replace(0, 1, surnameBuilder.substring(0, 1).toUpperCase());


        System.out.println(nameBuilder.toString() + " " + surnameBuilder.toString());
    }

    public ZonedDateTime getBirthDateTimeInLA() {
        return LocalDateTime.of(birthDate, timeOfBirth).atZone(ZoneId.of("America/Los_Angeles"));
    }
}

class IllegalFormatPersonException extends Exception {
    IllegalFormatPersonException(String message) {
        super(message);
    }
}