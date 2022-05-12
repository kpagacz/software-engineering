import React from "react";
import styles from "./Navbar.module.css";
import { NavLink } from "react-router-dom";

const Navbar = () => {
  const navlinkCssClass = ({ isActive }) =>
    isActive ? styles["navlink--active"] : styles.navlink;
  return (
    <nav className={styles.navbar}>
      <ul className={styles.navlist}>
        <li>
          <NavLink to="/" className={navlinkCssClass}>
            Home
          </NavLink>
        </li>
        <li>
          <NavLink to="/archive" className={navlinkCssClass}>
            Archived
          </NavLink>
        </li>
        <li>
          <NavLink to="/settings" className={navlinkCssClass}>
            Settings
          </NavLink>
        </li>
      </ul>
    </nav>
  );
};

export default Navbar;
