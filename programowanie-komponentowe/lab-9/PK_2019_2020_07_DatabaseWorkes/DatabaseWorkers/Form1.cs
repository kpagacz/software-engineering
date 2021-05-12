using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DatabaseWorkers
{
    public partial class Form1 : Form
    {
        public static DatabaseWorkersDataContext DatabaseDC = new DatabaseWorkersDataContext();
        public Form1()
        {
            InitializeComponent();
            LoadWorkers();

            //listBoxWorkes.DisplayMember = "FirstName";
        }

        private void LoadWorkers()
        {
            listBoxWorkes.Items.Clear();
            foreach (Worker w in DatabaseDC.Worker)
            {
                listBoxWorkes.Items.Add(w);
            }
        }

        private void buttonSave_Click(object sender, EventArgs e)
        {
            if (IsWorkerFormValid())
            {
                Worker workerToSave = null;
                //edycja
                if (listBoxWorkes.SelectedItems.Count == 1)
                {
                    listBoxWorkes.Enabled = true;
                    buttonDelete.Visible = false;
                    buttonSave.Text = "Dodaj";
                    buttonDetails.Visible = false;
                    label6.Visible = false;

                    workerToSave = listBoxWorkes.SelectedItem as Worker;
                }
                //dodawanie
                else
                {
                    workerToSave = new Worker();
                    DatabaseDC.Worker.InsertOnSubmit(workerToSave);
                }

                workerToSave.FirstName = textBoxFirstName.Text;
                workerToSave.LastName = textBoxLastName.Text;
                workerToSave.DateBegin = dateTimePickerDateBegin.Value;
                workerToSave.Salary = numericUpDownSalary.Value;
                workerToSave.Manager = checkBoxManager.Checked;

                DatabaseDC.SubmitChanges();

                ClearForm();

                LoadWorkers();
            }
            else
            {
                MessageBox.Show("Formularz wypełniony niepoprawnie.");
            }
        }

        private bool IsWorkerFormValid()
        {
            if(textBoxFirstName.Text.Length==0)
            {
                return false;
            }
            if (textBoxLastName.Text.Length == 0)
            {
                return false;
            }
            if (dateTimePickerDateBegin.Value.Day > DateTime.Today.Day)
            {
                return false;
            }
            return true;
        }

        private void ClearForm()
        {
            textBoxFirstName.Text = "";
            textBoxLastName.Text = "";
            dateTimePickerDateBegin.Value = DateTime.Today;
            numericUpDownSalary.Value = numericUpDownSalary.Minimum;
            checkBoxManager.Checked = false;
        }

        private void listBoxWorkes_SelectedIndexChanged(object sender, EventArgs e)
        {
            if(listBoxWorkes.SelectedItems.Count==1)
            {
                listBoxWorkes.Enabled = false;
                buttonSave.Text = "Zmień";
                buttonDelete.Visible = true;
                buttonDetails.Visible = true;
                label6.Visible = true;

                Worker selectedWorker = listBoxWorkes.SelectedItem as Worker;

                textBoxFirstName.Text = selectedWorker.FirstName;
                textBoxLastName.Text = selectedWorker.LastName;
                dateTimePickerDateBegin.Value = selectedWorker.DateBegin;
                numericUpDownSalary.Value = selectedWorker.Salary;
                checkBoxManager.Checked = selectedWorker.Manager;
                updateLabelReprimands(selectedWorker);

            }
        }

        private void updateLabelReprimands(Worker selectedWorker)
        {
            label6.Text = "Nagany: " + selectedWorker.Reprimand.Sum(x => x.PenaltyPoints) + " / 200";
        }

        private void buttonDelete_Click(object sender, EventArgs e)
        {
            if (listBoxWorkes.SelectedItems.Count == 1)
            {
                Worker selectedWorker = listBoxWorkes.SelectedItem as Worker;

                DatabaseDC.Worker.DeleteOnSubmit(selectedWorker);

                DatabaseDC.SubmitChanges();

                listBoxWorkes.Enabled = true;
                buttonSave.Text = "Dodaj";
                buttonDelete.Visible = false;
                buttonDetails.Visible = false;
                label6.Visible = false;
                
                ClearForm();

                LoadWorkers();
            }
        }

        private void buttonDetails_Click(object sender, EventArgs e)
        {
            if (listBoxWorkes.SelectedItems.Count == 1)
            {
                Worker selectedWorker = listBoxWorkes.SelectedItem as Worker;
                FormReprimands fr = new FormReprimands(selectedWorker);
                fr.ShowDialog();
                label6.Text = fr.getPenaltyPoints();                
            }
        }
    }
}
