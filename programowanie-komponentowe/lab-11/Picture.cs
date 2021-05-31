using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace lab_11
{
    class Picture
    {
        List<Shape> shapes;

        internal List<Shape> Shapes { get => shapes; set => shapes = value; }

        public void Draw(Graphics graphic)
        {
            foreach(Shape shape in Shapes) 
            {
                shape.Draw(graphic);
            }
        }

        public Picture()
        {
            Shapes = new List<Shape>();
        }

        public void writeSvg(XmlWriter writer)
        {
            writer.WriteDocType("html", "-//W3C//DTD XHTML 1.0 Transitional//EN", "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd", null);
            writer.WriteStartElement("html");
            writer.WriteStartElement("body");
            writer.WriteStartElement("svg", "http://www.w3.org/2000/svg");
            writer.WriteAttributeString("width", "1920");
            writer.WriteAttributeString("height", "1080");
            foreach (Shape shape in shapes)
            {
                shape.ToSvg(writer);
            }
            writer.WriteEndElement();
            writer.WriteEndElement();
        }
    }
}
