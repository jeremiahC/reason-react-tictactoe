module Player = {
    type pos = (int, int);
    type move = 
      | Circle
      | Cross;
};

module Status = {
    type indicator = 
      | Draw
      | Winner
      | Ongoing;
};

module Game = {
    type cells = array(array(string));

    let countFilled = (cells) => {
        let cellToList = Array.to_list(cells);
        let cells = Array.concat(cellToList);

        let result = Array.map((cell) => {
            if (cell != "") {
                1;
            } else {
                0;
            }
        }, cells);

        Array.fold_right((+), result, 0);
    };

    let checker = (cells: cells) => {
        //pattern for row 
        let patterns = [
            (cells[0][0], cells[0][1], cells[0][2]),
            (cells[1][0], cells[1][1], cells[1][2]),
            (cells[2][0], cells[2][1], cells[2][2]),

            //pattern for column
            (cells[0][0], cells[1][0], cells[2][0]),
            (cells[0][1], cells[1][1], cells[2][1]),
            (cells[0][2], cells[1][2], cells[2][2]),

            //diagonal pattern
            (cells[0][0], cells[1][1], cells[2][2]),
            (cells[0][2], cells[1][1], cells[2][0])
        ];

        
        let hasWinner = List.filter((pattern) => 
            pattern == ("X", "X", "X") ||
            pattern == ("O", "O", "O"), patterns);

        if (hasWinner != []) {
            Status.Winner;
        }  else if (countFilled(cells) == 9 && hasWinner == []) {
            Status.Draw;
        } else {
            Status.Ongoing;
        }
    }
}

module State = {
    type cells =
      | Empty
      | Marked(Player.move, (int, int));

    type t = {
        turn: Player.move,
        move: array(array(string)),
        status: Status.indicator,
        winner: string
    };

    let initial_state = {
        turn: Cross,
        move: Array.make_matrix(3, 3, ""),
        status: Ongoing,
        winner: ""
    };

    let moveReducer = (state, action) => {
        let new_state =
            switch (action) {
            /* If player one it will move x  */
            | Marked(Cross, (x, y)) => {
                state.move[x][y] = "X";
                {
                    ...state,
                    turn: Circle,
                    status: switch (Game.checker(state.move)) {
                    | Winner => Winner;
                    | Ongoing => Ongoing;
                    | Draw => Draw;
                    },
                    winner: switch (Game.checker(state.move)) {
                    | Winner => "X";
                    | Ongoing => "";
                    | Draw => "";
                    }
                }
            };
            | Marked(Circle, (x, y)) => {
                state.move[x][y] = "O";
                {
                    ...state,
                    turn: Cross,
                    status: switch (Game.checker(state.move)) {
                    | Winner => Winner;
                    | Ongoing => Ongoing;
                    | Draw => Draw;
                    },
                    winner: switch (Game.checker(state.move)) {
                    | Winner => "O";
                    | Ongoing => "";
                    | Draw => "";
                    }
                }
            };
            | Empty => state;
            };

        new_state;
    };
};