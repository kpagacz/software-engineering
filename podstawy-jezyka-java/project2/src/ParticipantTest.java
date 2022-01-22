import org.junit.jupiter.api.Test;

import java.util.Calendar;

import static org.junit.jupiter.api.Assertions.*;

class ParticipantTest {
    @Test
    void constructorDoesNotThrow() {
        assertDoesNotThrow(() -> new Participant("Maria" ,"Malysa", Calendar.getInstance()));
    }

    @Test
    void getGender() {
        Participant p = new Participant("Maria" ,"Malysa", Calendar.getInstance());
        assertEquals(Participant.Gender.FEMALE, p.getGender());
        p = new Participant("Konrad" ,"Pagacz", Calendar.getInstance());
        assertEquals(Participant.Gender.MALE, p.getGender());
    }

    @Test
    void getCategory() {
        Calendar date = Calendar.getInstance();
        date.set(Calendar.YEAR, 1900);
        Participant p = new Participant("Konrad" ,"Pagacz", date);
        assertEquals("M4", p.getCategory());

        p = new Participant("Antonina", "Kubiak", date);
        assertEquals("F4", p.getCategory());
    }

    @Test
    void getAgeCategory() {
        Calendar date = Calendar.getInstance();
        int currentYear = date.get(Calendar.YEAR);
        Participant p = new Participant("Konrad" ,"Pagacz", date);

        date.set(Calendar.YEAR, currentYear - 19);
        assertEquals(1, p.getAgeCategory());

        date.set(Calendar.YEAR, currentYear - 20);
        assertEquals(2, p.getAgeCategory());

        date.set(Calendar.YEAR, currentYear - 30);
        assertEquals(3, p.getAgeCategory());

        date.set(Calendar.YEAR, currentYear - 40);
        assertEquals(4, p.getAgeCategory());
    }
}