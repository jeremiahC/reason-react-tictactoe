let cell = (array, event, status) => {
    Array.mapi(
        (cell, value) => {
            <button
                key={string_of_int(cell)}
                id={string_of_int(cell)}
                className="field"
                onClick={event}
                disabled={value != "" || status != ""? true : false}
            >{React.string(value)}</button>
        },
        array
    )
};

[@react.component]
let make = (~row, ~event, ~status) => {
    {cell(row, event, status) |> ReasonReact.array}
};