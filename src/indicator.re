[@react.component]
let make = (~status) => {
    <div className="indicator">{ React.string(status) }</div>
};