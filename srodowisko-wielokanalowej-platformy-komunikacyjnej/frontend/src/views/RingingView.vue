<template>
  <div class="box">
    <div class="text">Zaraz nastąpi połączenie z konsultantem.</div>
  </div>
</template>

<script lang="ts">
import { defineComponent } from 'vue'
import ViewManager from '../services/ViewManager'

export default defineComponent({
  name: 'RingingView',
  mounted(): void {
    ViewManager.checkStatus()
  },
})
</script>
