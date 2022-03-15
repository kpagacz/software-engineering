/**
 * This module applies the middleware functions required for all the endpoints
 * in the backend.
 *
 * @module middleware/index
 */
const cors = require("cors");
const bodyParser = require("body-parser");

/**
 * Applies the Cross-Origin Resource Sharing policy of the backend, filters out
 * the unwanted HTTP request types and sets up the cookies parser.
 *
 * @function
 * @param {Object} app The Axios router object.
 * @name applyMiddleware
 */
module.exports = (app) => {
  app.use(
    cors({
      credentials: true,
      allowedHeaders: ["Content-Type", "Authorization"],
      origin: (origin, callback) => {
        if (!origin) return callback(null, true);
        return callback(null, true);
      },
    })
  );
  app.use(bodyParser.json());
};
