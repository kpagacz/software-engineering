package sample;

import javafx.event.ActionEvent;
import javafx.scene.control.CheckBox;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import model.Person;
import model.Student;

public class Controller {
    public CheckBox check_student;
    public TextField text_name;
    public TextField text_surname;
    public TextField text_major;
    public TextArea text_output;

    public void add_person(ActionEvent actionEvent) {
        String name = text_name.getText();
        String surname = text_surname.getText();
        String major = null;
        Person new_person = null;

        if(check_student.isSelected()) {
            major = text_major.getText();
            new_person = new Student(name, surname, major);
        } else {
            new_person = new Person(name, surname);
        }

        text_output.setText(new_person + "\n" + text_output.getText());
    }

    public void show_major(ActionEvent actionEvent) {
        if(check_student.isSelected()) {
            text_major.setDisable(false);
        } else {
            text_major.setVisible(true);
        }
    }
}
