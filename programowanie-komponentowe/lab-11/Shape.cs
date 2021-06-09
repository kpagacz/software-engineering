using System.Drawing;
using System.Text;
using System.Xml;

namespace lab_11
{
    abstract internal class Shape
    {
        protected Pen pen;
        abstract public void Draw(Graphics graphic);
        public Shape(Pen pen)
        {
            this.pen = pen;
        }
        abstract public void ToSvg(XmlWriter writer);
    }

    class Line : Shape
    {
        Point point1, point2;
        public override void Draw(Graphics graphic)
        {
            graphic.DrawLine(pen, point1, point2);
        }

        public Line(Pen pen, Point p1, Point p2) : base(pen)
        {
            point1 = p1;
            point2 = p2;
        }

        public override void ToSvg(XmlWriter writer)
        {
            writer.WriteStartElement("line");
            writer.WriteAttributeString("x1", point1.X.ToString());
            writer.WriteAttributeString("y1", point1.Y.ToString());
            writer.WriteAttributeString("x2", point2.X.ToString());
            writer.WriteAttributeString("y2", point2.Y.ToString());
            writer.WriteAttributeString("style", $"stroke:rgb({pen.Color.R},{pen.Color.G},{pen.Color.B});stroke-width:{pen.Width}");
            writer.WriteEndElement();
        }
    }
}