open Model_indicator.State;

[@react.component]
let make = (~status) => {
    <div>{ React.string(status) }</div>
};