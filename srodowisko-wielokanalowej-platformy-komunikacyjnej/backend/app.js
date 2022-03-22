const express = require("express");
const middleware = require("./middleware/index.js");
const {Server} = require("socket.io");

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

const server = app.listen(3000, () => {
  console.log("app listening on port 3000");
});
const io = new Server(server);

io.on("connection", (socket) => {
  console.log("Socket connected");
  io.emit("status", 5555);
  socket.on("message", (message) => {
    console.log("message", message);
  });
  socket.on("disconnect", () => {
    console.log("User disconnected");
  });
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
    var oldStatus = null;
    var interval = setInterval(async () => {
      var currentStatus = await bridge.getStatus();
      if (currentStatus !== oldStatus) {
        oldStatus = currentStatus
        io.emit('status', currentStatus)
     }
     if (currentStatus === 'ANSWERED') {
        clearInterval(interval)
     }
    }, 1000);
    res.json({ success: true });
  } catch (e) {
    console.log(e);
    res.json({ success: false, msg: JSON.stringify(e.message) });
  }
});
