open Model_board.State;

[@react.component]
let make = () => {
    let (state, dispatch) = React.useReducer(moveReducer, initial_state);
    // let (indicatorState, indicatorDispatch) = React.useReducer(statusReducer, initial_state);

    let handleClick = (e) => {
        ReactEvent.Mouse.preventDefault(e);
        let element = e->ReactEvent.Mouse.target;
        let position = (element##parentNode##id, element##id);
    
        switch (state.turn) {
        | Cross => dispatch(Marked(Cross, position));
        | Circle => dispatch(Marked(Circle, position));
        };
    };

    let indicator = () => {
        switch (state.status) {
        | Winner => <Indicator status={"Winner is Player: " ++ state.winner} />
        | Draw => <Indicator status="Draw" />
        | Ongoing => <Indicator status="Ongoing" />
        };  
    };

    
    let board = Array.mapi(
        (index, item) => {
            <div id={string_of_int(index)}>
                <Cells  
                    key={string_of_int(index)}
                    row=item
                    event={handleClick}
                    status={state.winner}
                />
            </div>
        },
        state.move
    );

    <div>
        <div className="board">
            { ReasonReact.array(board) }
        </div>
        <div className="inicator">
            { indicator() }
        </div>
    </div>;
}