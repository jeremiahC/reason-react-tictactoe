// Generated by BUCKLESCRIPT VERSION 5.0.4, PLEASE EDIT WITH CARE
'use strict';


var Action = /* module */[];

var intial_state_002 = /* move : array */[
  /* array */[
    "",
    "",
    ""
  ],
  /* array */[
    "",
    "",
    ""
  ],
  /* array */[
    "",
    "",
    ""
  ]
];

var intial_state = /* record */[
  /* turn : Cross */1,
  /* gstatus : Ongoing */1,
  intial_state_002
];

function reducer(state, action) {
  var new_state = action ? /* record */[
      /* turn : Circle */0,
      /* gstatus */state[/* gstatus */1],
      /* move */state[/* move */2]
    ] : /* record */[
      /* turn : Cross */1,
      /* gstatus */state[/* gstatus */1],
      /* move */state[/* move */2]
    ];
  console.log(new_state);
  return /* () */0;
}

var State = /* module */[
  /* intial_state */intial_state,
  /* reducer */reducer
];

exports.Action = Action;
exports.State = State;
/* No side effect */
