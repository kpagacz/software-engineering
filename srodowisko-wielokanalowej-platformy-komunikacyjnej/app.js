import express from "express";

const app = express();
const port = 3000;

app.get("/", (req, res) => {
  res.send("Hello world");
});

app.get("/call/status", (req, res) => {
  var id = null;
  const status = req.params.status;
  getRandomId((randomId) => {
    console.log(randomId);
    id = randomId;
  });
  console.log("sending response");
  res.json({ success: true, id: id, status: status });
});

app.listen(port, () => {
  console.log("Listening on port: " + port);
});

const getRandomId = (callback) => {
  setTimeout(() => {
    var random = Math.round(Math.random() * 10000);
    callback(random);
  }, Math.round(Math.random() * 1000));
};
