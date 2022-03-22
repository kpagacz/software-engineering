<template>
  <div class="box">
    <div class="text">Dziękujemy za połączenie!</div>
    <button @click="backToStart"> Powrót do strony głównej </button>
  </div>
</template>

<script lang="ts">
import { defineComponent } from 'vue'
import ViewManager from '../services/ViewManager'

export default defineComponent({
  name: 'startView',
  mounted(): void {
    ViewManager.stopCheckingStatus()
  },
  methods: {
    backToStart(): void {
      this.$router.push({ name: 'start' })
    }
  }
})
</script>
