using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;

namespace lab_7
{
    class PacManGame
    {
        public enum Field
        {
            Wall,
            Empty,
            Coin
        }

        public enum Direction
        {
            Up, Down, Left, Right
        }

        public enum GameState
        {
            InProgress, Lost, Won
        }
        Field[,] board;
        Point pacMan;
        Direction pacManDirection;
        List<Point> ghosts;
        int score = 0;
        int total_coins = 0;
        GameState state;


        public Field[,] Board { get => board; set => board = value; }
        public Point PacMan { get => pacMan; set => pacMan = value; }
        public List<Point> Ghosts { get => ghosts; set => ghosts = value; }
        internal Direction PacManDirection { get => pacManDirection; set => pacManDirection = value; }
        public int Score { get => score; private set => score = value; }
        internal GameState State { get => state; private set => state = value; }

        public PacManGame()
        {
            String raw_map = Properties.Resource1.pacman_map_1.Replace("\r", "");
            String[] map = raw_map.Split('\n');
            board = new Field[map.Length - 1, map[0].Length];
            Ghosts = new List<Point>();

            for(int i = 0; i < map.Length - 1; i++)
            {
                for(int j = 0; j < map[0].Length; j++)
                {
                    switch(map[i].ElementAt(j))
                    {
                        case '*':
                            board[i, j] = Field.Wall;
                            break;
                        case '.':
                            board[i, j] = Field.Coin;
                            ++total_coins;
                            break;
                        case '@':
                            PacMan = new Point(i, j);
                            board[i, j] = Field.Empty;
                            break;
                        case '$':
                            Ghosts.Add(new Point(i, j));
                            board[i, j] = Field.Empty;
                            break;
                        case ' ':
                            board[i, j] = Field.Empty;
                            break;
                    }
                }
            }

            PacManDirection = Direction.Right;
            State = GameState.InProgress;
        }

        public void movePackMan()
        {
            switch (PacManDirection)
            {
                case PacManGame.Direction.Left:
                    if(board[pacMan.X, pacMan.Y - 1] != Field.Wall)
                    {
                        pacMan.Y--;
                    } else
                    {
                        if (board[pacMan.X, pacMan.Y + 1] != Field.Wall) ++pacMan.Y;
                        pacManDirection = Direction.Right;
                    }
                    break;
                case PacManGame.Direction.Right:
                    if (board[pacMan.X, pacMan.Y + 1] != Field.Wall)
                    {
                        pacMan.Y++;
                    }
                    else
                    {
                        if (board[pacMan.X, pacMan.Y - 1] != Field.Wall) --pacMan.Y;
                        pacManDirection = Direction.Left;
                    }
                    break;
                case PacManGame.Direction.Up:
                    if (board[pacMan.X - 1, pacMan.Y] != Field.Wall)
                    {
                        pacMan.X--;
                    }
                    else
                    {
                        if (board[pacMan.X + 1, pacMan.Y] != Field.Wall) ++pacMan.X;
                        pacManDirection = Direction.Down;
                    }
                    break;
                case PacManGame.Direction.Down:
                    if (board[pacMan.X + 1, pacMan.Y] != Field.Wall)
                    {
                        ++pacMan.X;
                    }
                    else
                    {
                        if (board[pacMan.X - 1, pacMan.Y] != Field.Wall) --pacMan.X;
                        pacManDirection = Direction.Up;
                    }
                    break;
            }

            if(board[pacMan.X, pacMan.Y] == Field.Coin)
            {
                board[pacMan.X, pacMan.Y] = Field.Empty;
                ++score;
            }

            if(score == total_coins)
            {
                state = GameState.Won;
            }

            foreach(Point ghost in ghosts)
            {
                if (ghost.Equals(pacMan)) State = GameState.Lost;
            }
        }

        internal void moveGhosts()
        {
            for(int i = 0; i < ghosts.Count; i++)
            {
                Point new_location = new Point();
                Point ghost = ghosts[i];
                if (ghost.X < pacMan.X && board[ghost.X + 1, ghost.Y] != Field.Wall)
                {
                    new_location.X = ghost.X + 1;
                    new_location.Y = ghost.Y;
                }
                else if (ghost.X > pacMan.X && board[ghost.X - 1, ghost.Y] != Field.Wall)
                {
                    new_location.X = ghost.X - 1;
                    new_location.Y = ghost.Y;
                }
                else if (ghost.Y < pacMan.Y && board[ghost.X, ghost.Y + 1] != Field.Wall)
                {
                    new_location.X = ghost.X;
                    new_location.Y = ghost.Y + 1;
                } else if(ghost.Y > pacMan.Y && board[ghost.X, ghost.Y - 1] != Field.Wall)
                {
                    new_location.X = ghost.X;
                    new_location.Y = ghost.Y - 1;
                } else
                {
                    new_location.X = ghost.X;
                    new_location.Y = ghost.Y;
                }

                ghosts[i] = new_location;

                if (new_location.Equals(pacMan)) State = GameState.Lost;
            }
        }
    }
}
