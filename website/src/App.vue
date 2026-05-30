<script setup>
import NavBar from "./components/NavBar.vue";
</script>

<template>
  <NavBar />
  <main class="max-w-[1400px] mx-auto p-4 sm:p-6">
    <router-view />
  </main>
</template>
