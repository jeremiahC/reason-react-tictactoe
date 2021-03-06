// Generated by BUCKLESCRIPT VERSION 5.0.4, PLEASE EDIT WITH CARE
'use strict';

var $$Array = require("bs-platform/lib/js/array.js");
var React = require("react");

function cell(array, $$event, status) {
  return $$Array.mapi((function (cell, value) {
                var match = value !== "" || status !== "";
                return React.createElement("button", {
                            key: String(cell),
                            className: "field",
                            id: String(cell),
                            disabled: match ? true : false,
                            onClick: $$event
                          }, value);
              }), array);
}

function Cells(Props) {
  var row = Props.row;
  var $$event = Props.event;
  var status = Props.status;
  return cell(row, $$event, status);
}

var make = Cells;

exports.cell = cell;
exports.make = make;
/* react Not a pure module */
