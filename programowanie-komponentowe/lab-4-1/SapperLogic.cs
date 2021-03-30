using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab_4_1
{
    class SapperLogic
    {
        // Enums
        public enum FieldTypeEnum
        {
            Bomb,
            BombCount,
            Empty
        }
        public enum GameStateEnum
        {
            Won,
            Lost,
            InProgress
        }

        // attributes
        Random generator = new Random();
        Field[,] board;
        GameStateEnum state;
        internal GameStateEnum State { get => state; private set => state = value; }
        int uncoveredCount;
        public int UncoveredCount { get => uncoveredCount; private set => uncoveredCount = value; }
        int boardBombCount;
        public int boardWidth
        {
            get { return (int)board.GetLongLength(0); }
        }
        public int boardHeight
        {
            get { return (int)board.GetLongLength(1); }
        }
        class Field
        {
            bool covered;
            public bool Covered { get => covered; }
            int bombCount;
            public int BombCount { get => bombCount; set => bombCount = value; }
            FieldTypeEnum fieldType;
            public FieldTypeEnum FieldType { get => fieldType; private set => fieldType = value; }

            public Field(FieldTypeEnum type)
            {
                FieldType = type;
                BombCount = 0;
                covered = true;
            }

            public void uncover()
            {
                covered = false;
            }
        }

        public SapperLogic(int width, int height, int bombCount)
        {
            board = new Field[width, height];
            int fieldCount = width * height;
            int[] bombFields = sampleKFromN(bombCount, fieldCount);

            for (int row = 0; row < boardWidth; row++)
            {
                for (int col = 0; col < boardHeight; col++)
                {
                    board[row, col] = new Field(FieldTypeEnum.Empty);
                }
            }

            for (int i = 0; i < bombCount; i++)
            {
                board[bombFields[i] / boardHeight, bombFields[i] % boardHeight] = new Field(FieldTypeEnum.Bomb);
            }

            State = GameStateEnum.InProgress;
            UncoveredCount = 0;
            this.boardBombCount = bombCount;

            countBombsInFields();
        }

        private void countBombsInFields()
        {
            for(int i = 0; i < boardWidth; i++)
            {
                for(int j = 0; j < boardHeight; j++)
                {
                    int count = 0;
                    foreach(int k in new int[]{ -1, 0, 1})
                        foreach(int l in new int[] { -1, 0, 1 })
                        {
                            int x = i + k, y = j + l;
                            try
                            {
                                if(getFieldType(new Point(x, y)) == FieldTypeEnum.Bomb)
                                {
                                    count += 1;
                                }
                            } catch(Exception e)
                            {
                                continue;
                            }
                        }
                    board[i, j].BombCount = count;
                }
            }
        }

        internal int getBombCount(Point tag)
        {
            return board[tag.X, tag.Y].BombCount;
        }

        int[] sampleKFromN(int k, int n)
        {
            int[] sample = new int[k];

            for(int i = 0; i < k; i++)
            {
                sample[i] = i;
            }

            for(int i = k; i < n; i++)
            {
                int j = generator.Next(0, i);
                if (j < k) sample[j] = i;
            }

            return sample;
        }

        internal FieldTypeEnum getFieldType(Point point)
        {
            return board[point.X, point.Y].FieldType;
        }


        internal void uncoverField(Point tag)
        {
            if(getFieldType(tag) == FieldTypeEnum.Bomb)
            {
                for (int row = 0; row < boardWidth; row++)
                {
                    for (int col = 0; col < boardHeight; col++)
                    {
                        board[row, col].uncover();
                    }
                }

                State = GameStateEnum.Lost;
            } else
            {
                board[tag.X, tag.Y].uncover();
                UncoveredCount++;
                if (UncoveredCount == boardWidth * boardHeight - boardBombCount)
                {
                    State = GameStateEnum.Won;  
                }
            }
        }

        internal bool isFieldCovered(Point point)
        {
            return board[point.X, point.Y].Covered;
        }
    }
}
