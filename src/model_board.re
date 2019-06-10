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

    let checker = (cells: cells) => {
        //pattern for row
        let pattern1 = (cells[0][0], cells[0][1], cells[0][2]);
        let pattern2 = (cells[1][0], cells[1][1], cells[1][2]);
        let pattern3 = (cells[2][0], cells[2][1], cells[2][2]);

        //pattern for column
        let pattern4 = (cells[0][0], cells[1][0], cells[2][0]);
        let pattern5 = (cells[0][1], cells[1][1], cells[2][1]);
        let pattern6 = (cells[0][2], cells[1][2], cells[2][2]);

        //diagonal pattern
        let pattern7 = (cells[0][0], cells[1][1], cells[2][2]);
        let pattern8 = (cells[0][2], cells[1][1], cells[2][0]);

        if (pattern1 == ("X", "X", "X") || pattern1 == ("O", "O", "O")) {
            true;
        } else if (pattern2 == ("X", "X", "X") || pattern2 == ("O", "O", "O")) {
            true;
        } else if (pattern3 == ("X", "X", "X") || pattern3 == ("O", "O", "O")) {
            true;
        } else if (pattern4 == ("X", "X", "X") || pattern4 == ("O", "O", "O")) {
            true;
        } else if (pattern5 == ("X", "X", "X") || pattern5 == ("O", "O", "O")) {
            true;
        } else if (pattern6 == ("X", "X", "X") || pattern6 == ("O", "O", "O")) {
            true;
        } else if (pattern7 == ("X", "X", "X") || pattern7 == ("O", "O", "O")) {
            true;
        } else if (pattern8 == ("X", "X", "X") || pattern8 == ("O", "O", "O")) {
            true;
        } else {
            false;
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
                    | true => Winner;
                    | false => Ongoing;
                    },
                    winner: switch (Game.checker(state.move)) {
                    | true => "X";
                    | false => "";
                    }
                }
            };
            | Marked(Circle, (x, y)) => {
                state.move[x][y] = "O";
                {
                    ...state,
                    turn: Cross,
                    status: switch (Game.checker(state.move)) {
                    | true => Winner;
                    | false => Ongoing;
                    },
                    winner: switch (Game.checker(state.move)) {
                    | true => "O";
                    | false => "";
                    }
                }
            };
            | Empty => state;
            };

        new_state;
    };
};