namespace lab_6
{
    partial class People
    {
        public override string ToString()
        {
            return surname + " " + name + ".";
        }

        public string Description
        {
            get
            {
                return surname + " " + name + ". Addresses: " + this.Address.Count;
            }
        }
    }
}