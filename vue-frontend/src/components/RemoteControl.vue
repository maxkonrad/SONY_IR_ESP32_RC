<template>
    <div class="player-remote">
    <button @click="toggleOperate">Operate</button>
    <button @click="volumeUp">Volume Up</button>
    <button @click="volumeDown">Volume Down</button>
    <button @click="play">Play</button>
    <button @click="stop">Stop</button>
  </div>
</template>

<script>
export default {
  methods: {
    toggleOperate() {
        
    },
    volumeUp() {
    },
    volumeDown() {
    },
    play() {
    },
    stop() {
    },
  },
  data() {
    return {
        timer: null,
    }
  }
};
</script>

<style scoped>
    .player-remote{
        text-align: center;
    }

    button {
        font-size: larger;
    }
</style>