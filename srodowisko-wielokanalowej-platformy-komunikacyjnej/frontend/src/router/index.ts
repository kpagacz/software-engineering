import { createRouter, createWebHistory, RouteRecordRaw } from 'vue-router'
import Start from '@/views/StartView.vue'
import Ringing from '@/views/RingingView.vue'
import Failed from '@/views/FailedView.vue'
import Connected from '@/views/ConnectedView.vue'
import Answered from '@/views/AnsweredView.vue'

const routes: Array<RouteRecordRaw> = [
  {
    path: '/',
    name: 'start',
    component: Start,
  },
  {
    path: '/',
    name: 'ringing',
    component: Ringing,
  },
  {
    path: '/',
    name: 'failed',
    component: Failed,
  },
  {
    path: '/',
    name: 'connected',
    component: Connected,
  },
  {
    path: '/',
    name: 'answered',
    component: Answered,
  },
]

const router = createRouter({
  history: createWebHistory(),
  routes
})

export default router
