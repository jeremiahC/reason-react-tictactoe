module Status = {
    type indicator = 
      | Draw
      | Winner
      | Ongoing;
}

module Game = {
    type cells = array(array(string));
    let checker = (cells: cells, state) => {
        
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
    type t = {
        status: Status.indicator,
    };

    let initial_state = {
        status: Ongoing,
    };

    let reducer = (state, cells) => {
        let new_state = switch (Game.checker(cells, state)) {
        | true => {...state, status: Winner};
        | false => {...state, status: Draw};
        };

        new_state;
            
    }
}