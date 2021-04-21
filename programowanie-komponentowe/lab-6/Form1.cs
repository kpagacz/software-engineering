using System;
using System.Linq;
using System.Windows.Forms;

namespace lab_6
{
    public partial class Form1 : Form
    {
        lab_6_dbDataContext db;
        People chosenPerson;

        public Form1()
        {
            InitializeComponent();
            db = new lab_6_dbDataContext();
            listBoxPeople.DisplayMember = "Description";

            foreach(People p in db.People)
            {
                Address a = new Address();
                a.street = "Ulica";
                a.number = "12";
                a.People = p;
            }
            readPeople();
        }
        private void readPeople()
        {
            //foreach (People p in db.People.Where(x => x.surname == "Pagacz"));
            //{
            //    listBoxPeople.Items.Add(p);
            //}
            listBoxPeople.Items.Clear();
            listBoxPeople.Items.AddRange(db.People.ToArray());
        }

        private void buttonSavePerson_Click(object sender, System.EventArgs e)
        {
            People newPerson;
            if(chosenPerson != null)
            {
                newPerson = chosenPerson;
            } else
            {
                newPerson = new People();
                db.People.InsertOnSubmit(newPerson);
            }
            newPerson.name = textBoxName.Text;
            newPerson.surname = textBoxSurname.Text;
            newPerson.birth_date = dateTimePickerBirthDate.Value;
            newPerson.height = (int)numericUpDownHeight.Value;

            db.SubmitChanges();

            buttonConfirm.Text = "Add person";
            chosenPerson = null;
            textBoxName.Text = "";
            textBoxSurname.Text = "";
            dateTimePickerBirthDate.Value = DateTime.Parse("2000-01-01");

            readPeople();
        }

        private void listBoxPeople_SelectedIndexChanged(object sender, System.EventArgs e)
        {
            chosenPerson = listBoxPeople.SelectedItem as People;

            textBoxName.Text = chosenPerson.name;
            textBoxSurname.Text = chosenPerson.surname;
            dateTimePickerBirthDate.Value = chosenPerson.birth_date;
            numericUpDownHeight.Value = chosenPerson.height;

            buttonConfirm.Text = "Update person";
        }

        private void buttonDelete_Click(object sender, EventArgs e)
        {
            if(chosenPerson != null)
            {
                db.People.DeleteOnSubmit(chosenPerson);
                db.SubmitChanges();
                
                buttonConfirm.Text = "Add person";
                chosenPerson = null;
                textBoxName.Text = "";
                textBoxSurname.Text = "";
                dateTimePickerBirthDate.Value = DateTime.Parse("2000-01-01");

                readPeople();
            }
        }
    }
}
