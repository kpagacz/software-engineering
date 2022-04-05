<template>
  <div>
    <div class="header clearfix">Zadzwonimy do Ciebie w ciągu 26 sekund.</div>
    <label class="form-label clearfix" for="form-number">
      Wprowadź numer
    </label>
    <input v-model="number" class="form-number clearfix" id="form-number" />
    <div class="call-button" @click="call()">Zadzwoń teraz</div>
  </div>
</template>

<script lang="ts">
import { defineComponent } from "vue";
import * as config from "../../../backend/config.js";

export default defineComponent({
  data: () => ({
    number: "",
  }),
  methods: {
    async call() {
      const responseStream = await fetch( `${config.api.url}${config.api.prefix}/call`, {
        method: 'POST',
        headers: {
          'Content-type': 'application/json; charset=UTF-8',
        },
        body: JSON.stringify({ number: this.number }),
      })
      const response = await responseStream.json()
      this.$router.push({ name: 'ringing', params: { callsId: response.id } })
    },
  },
});
</script>
