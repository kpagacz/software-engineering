import React from "react";
import { FacebookMessengerIcon, TwitterIcon, WhatsappIcon } from "react-share";
import styles from "./ShareBar.module.css";

const ShareBar = () => {
  const iconSize = "1.5em";
  const round = true;
  return (
    <div className={styles["sharebar-container"]}>
      <div>
        <FacebookMessengerIcon size={iconSize} round={round} />
      </div>
      <div>
        <TwitterIcon size={iconSize} round={round} />
      </div>
      <div>
        <WhatsappIcon size={iconSize} round={round} />
      </div>
    </div>
  );
};

export default ShareBar;
