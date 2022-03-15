const express = require("express");
const middleware = require("./middleware/index.js");
// middleware
const app = express();
middleware(app);

const Dialer = require("dialer").Dialer;

const config = {
  url: "https://uni-call.fcc-online.pl",
  login: "focus09",
  password: "89o2hjbfdgd",
};
Dialer.configure(config);

app.listen(3000, () => {
  console.log("app listening on port 3000");
});

app.get("/test", async (req, res) => {
  res.json({ test: "test" });
});

app.post("/call/", async (req, res) => {
  try {
    console.log(req.body);
    const body = req.body;
    const number1 = body.number;
    const number2 = "794949545";
    bridge = await Dialer.call(number1, number2);
    res.json({ success: true });
  } catch (e) {
    console.log(e);
    res.json({ success: false, msg: JSON.stringify(e.message) });
  }
});
