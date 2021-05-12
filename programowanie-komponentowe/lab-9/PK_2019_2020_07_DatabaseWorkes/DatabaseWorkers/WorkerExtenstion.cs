using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DatabaseWorkers
{
    partial class Worker
    {
        public override string ToString()
        {
            return FirstName + " " + LastName + " (reprimands: " + this.Reprimand.Count + " penalty pts: " + 
                this.Reprimand.Sum(x => x.PenaltyPoints) + ")";
        }
    }
}
