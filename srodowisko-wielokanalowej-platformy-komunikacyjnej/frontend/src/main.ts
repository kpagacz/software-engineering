import { createApp } from 'vue'
import App from './App.vue'
import router from './router'
import io from 'socket.io-client';

const socket = io('http://localhost:3000', {
  reconnection: false,
  transports: ["websocket", "polling"]
});

createApp(App).use(router).mount('#app')
