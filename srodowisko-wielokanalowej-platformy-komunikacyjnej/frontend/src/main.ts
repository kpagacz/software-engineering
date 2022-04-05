import { createApp } from 'vue'
import App from './App.vue'
import router from './router'
import io from 'socket.io-client';
import * as config from '../../backend/config.js';

const socket = io(config.api.url, {
  reconnection: false,
  transports: ["websocket", "polling"],
  path: config.api.prefix + "/socket"
});

createApp(App).use(router).mount('#app')
