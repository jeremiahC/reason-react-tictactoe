open Model_board.State;

[@react.component]
let make = () => {
    let (state, dispatch) = React.useReducer(reducer, initial_state);
    let (indicatorState, indicatorDispatch) = 
        Model_indicator.State.(React.useReducer(reducer, initial_state));

    let handleClick = (e) => {
        ReactEvent.Mouse.preventDefault(e);
        let element = e->ReactEvent.Mouse.target;
        let position = (element##parentNode##id, element##id);

        switch (state.turn) {
        | "X" => dispatch(Cross(position));
        | "O" => dispatch(Circle(position));
        }

        indicatorDispatch(state.move);
    };

    let indicator = () => {
        switch (indicatorState.status) {
        | Winner => <Indicator status="Winner"/>
        | Draw => <Indicator status="Draw"/>
        | Ongoing => <Indicator status="Ongoing"/>
        };  
    };

    Js.log(indicator);
    let board = Array.mapi(
        (index, item) => {
            <div id={string_of_int(index)}>
                <Cells  
                    key={string_of_int(index)}
                    row=item
                    event={handleClick}
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
            // { indicator }
        </div>
    </div>;
}