module Action = {
    type pos = (int, int);
    type move = 
      | Circle(pos)
      | Cross(pos);
};

module State = {
    type t = {
        turn: string,
        move: array(array(string))
    };

    let initial_state = {
        turn: "X",
        move: Array.make_matrix(3, 3, "")
    };

    let reducer = (state, action) => {
        let new_state =
            switch (action) {
            /* If player one it will move x  */
            | Action.Cross((x, y)) => {
                state.move[x][y] = "X";
                {
                    ...state,
                    turn: "O",
                }
            };
            | Action.Circle((x, y)) => {
                state.move[x][y] = "O";
                {
                    ...state,
                    turn: "X",
                }
            };
            }

        new_state;
    };
};