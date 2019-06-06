let cell = (array, event) => {
    Array.mapi(
        (cell, value) => {
            <button
                key={string_of_int(cell)}
                id={string_of_int(cell)}
                className="field"
                onClick={event}
                disabled={value != "" ? true : false}
            >{React.string(value)}</button>
        },
        array
    )
};

[@react.component]
let make = (~row, ~event) => {
    {cell(row, event) |> ReasonReact.array}
};