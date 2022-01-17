import {
  Scene,
  Clock,
  PerspectiveCamera,
  WebGLRenderer,
  Group,
  CylinderGeometry,
  Mesh,
  Vector3,
  PCFSoftShadowMap,
  AmbientLight,
  MeshLambertMaterial,
  DirectionalLight,
  CameraHelper,
  DodecahedronGeometry,
  BoxGeometry,
  PlaneGeometry,
  TextureLoader,
  MeshBasicMaterial,
  SphereGeometry,
  ConeGeometry,
  TetrahedronGeometry,
  NumberKeyframeTrack,
  AnimationClip,
  AnimationMixer,
  LoopPingPong,
  VectorKeyframeTrack,
  QuaternionKeyframeTrack,
  LoopRepeat,
  Matrix4,
} from "three";
import { OrbitControls } from "three/examples/jsm/controls/OrbitControls.js";
import { mergeBufferGeometries } from "three/examples/jsm/utils/BufferGeometryUtils.js";

// const TextureLoader setup
const textureLoader = new TextureLoader();

// Functions to create meshes
// Island
const createIsland = () => {
  const orangeMaterial = new MeshLambertMaterial({ color: 0xff8c75 });
  const darkMaterial = new MeshLambertMaterial({ color: 0x5a6e6c });

  const layers = [];
  const island = new Group();
  for (var i = 0; i < 5; i++) {
    const h = 0.1;
    const geometry = new CylinderGeometry(8 - i - 0.01, 8 - i, h, 9);
    layers.push(new Mesh(geometry, orangeMaterial));
    layers[i].position.y = h * i;
    layers[i].receiveShadow = true;
    island.add(layers[i]);
  }
  layers[0].scale.x = 0.8;
  layers[1].scale.set(0.77, 1, 0.91);
  layers[1].rotation.y = ((2 * Math.PI) / 9) * 0.6;
  layers[2].scale.set(0.8, 1, 0.91);
  layers[2].rotation.y = ((2 * Math.PI) / 9) * 0.3;
  layers[3].scale.set(0.75, 1, 0.92);
  layers[3].rotation.y = ((2 * Math.PI) / 9) * 0.7;
  layers[4].scale.set(0.7, 1, 0.93);
  layers[4].rotation.y = ((2 * Math.PI) / 9) * 0.9;

  const geometryBase = new CylinderGeometry(8, 1, 10, 9);
  const base = new Mesh(geometryBase, darkMaterial);
  base.scale.x = layers[0].scale.x;
  base.position.y = -5;
  island.add(base);

  return island;
};

// Stone
const createStone = () => {
  const stoneMaterial = new MeshLambertMaterial({ color: 0x889a98 });
  const stoneGeometry = new DodecahedronGeometry();
  const stoneMesh = new Mesh(stoneGeometry, stoneMaterial);
  stoneMesh.castShadow = true;
  stoneMesh.receiveShadow = true;
  return stoneMesh;
};

// Frame
const createPainting = () => {
  const side = 0.45;
  const frameGroup = new Group();

  const frameGeometry = new BoxGeometry((16 / 9) * side, side, 0.1);
  const frameMaterial = new MeshLambertMaterial({ color: 0xc99c7e });
  const frame = new Mesh(frameGeometry, frameMaterial);
  frame.castShadow = true;
  frameGroup.add(frame);

  const paintingGeometry = new PlaneGeometry(
    (16 / 9) * (side - 0.1),
    side - 0.1
  );
  const paintingMaterial = new MeshBasicMaterial();
  textureLoader.load(
    "https://previews.123rf.com/images/nasaimages/nasaimages1811/nasaimages181100451/114532668-nebula-in-space-cosmic-background.jpg",
    (texture) => {
      paintingMaterial.map = texture;
      paintingMaterial.needsUpdate = true;
    }
  );
  const painting = new Mesh(paintingGeometry, paintingMaterial);
  painting.position.set(0, 0, 0.051);
  painting.castShadow = true;
  frameGroup.add(painting);

  frameGroup.castShadow = true;
  frameGroup.receiveShadow = true;

  return frameGroup;
};

// Cloud
const createCloud = () => {
  const part1 = new SphereGeometry(1.5, 4, 5);
  part1.translate(2, 0, 0);
  const part2 = new SphereGeometry(1.5, 4, 5);
  part2.translate(-2, 0, 0);
  const part3 = new SphereGeometry(2, 4, 5);

  const cloudGeometry = mergeBufferGeometries([part1, part2, part3]);
  const cloudMaterial = new MeshLambertMaterial({
    color: 0xc6bbb4,
    opacity: 0.9,
    transparent: true,
  });
  const cloud = new Mesh(cloudGeometry, cloudMaterial);
  cloud.receiveShadow = true;
  cloud.castShadow = true;
  return cloud;
};

// Tree
const createTree = (height, bubbleRadius) => {
  const treeGroup = new Group();

  const trunkGeometry = new CylinderGeometry(
    bubbleRadius / 10,
    bubbleRadius / 7,
    height,
    12,
    10
  );
  const trunkMaterial = new MeshLambertMaterial({ color: 0x8f7c70 });
  const trunk = new Mesh(trunkGeometry, trunkMaterial);
  trunk.position.set(0, height / 2, 0);
  trunk.castShadow = true;
  trunk.receiveShadow = true;
  treeGroup.add(trunk);

  const leavesGeometry = new TetrahedronGeometry(bubbleRadius, 1);
  const colorVariance = 0x00010;
  const leavesMaterial = new MeshLambertMaterial({
    color: 0x79b782 + Math.random() * 2 * colorVariance - colorVariance,
  });
  const leaves = new Mesh(leavesGeometry, leavesMaterial);
  leaves.position.set(0, height, 0);
  leaves.rotation.set(
    Math.random() * Math.PI,
    Math.random() * Math.PI,
    Math.random() * Math.PI
  );
  leaves.castShadow = true;
  leaves.receiveShadow = true;
  treeGroup.add(leaves);

  return treeGroup;
};

// Bird
const createBird = () => {
  const birdGroup = new Group();

  const bodyGeometry = new SphereGeometry(1, 30, 15);
  const bodyMaterial = new MeshLambertMaterial({ color: 0x308bec });
  const bodyMesh = new Mesh(bodyGeometry, bodyMaterial);
  bodyMesh.castShadow = true;
  bodyMesh.receiveShadow = true;
  birdGroup.add(bodyMesh);

  const headMesh = bodyMesh.clone();
  headMesh.position.set(0.6, 0.9, 0);
  headMesh.scale.set(0.6, 0.6, 0.6);
  headMesh.castShadow = true;
  headMesh.receiveShadow = true;
  birdGroup.add(headMesh);

  const beakGeometry = new ConeGeometry(0.3, 0.5);
  const beakMaterial = new MeshLambertMaterial({ color: 0xfea168 });
  const beak = new Mesh(beakGeometry, beakMaterial);
  beak.position.set(1.3, 0.9, 0);
  beak.rotation.set(0, 0, -Math.PI / 2);
  beak.receiveShadow = true;
  beak.castShadow = true;
  birdGroup.add(beak);

  const eyeGeometry = new SphereGeometry(0.1);
  const eyeMaterial = new MeshLambertMaterial({ color: 0x444444 });
  const leftEye = new Mesh(eyeGeometry, eyeMaterial);
  const rightEye = leftEye.clone();

  leftEye.position.set(1.1, 1.2, -0.15);
  rightEye.position.set(1.1, 1.2, 0.15);
  birdGroup.add(leftEye);
  birdGroup.add(rightEye);

  const wingGeometry = new TetrahedronGeometry(1, 1);
  const leftWing = new Mesh(wingGeometry, bodyMaterial);
  leftWing.position.set(0, 0, -1);
  leftWing.scale.set(0.3, 1, 0.3);
  leftWing.rotation.set(Math.PI / 4, 0, 0);
  leftWing.receiveShadow = true;
  leftWing.castShadow = true;
  birdGroup.add(leftWing);

  const rightWing = leftWing.clone();
  rightWing.position.set(0, 0, 1);
  rightWing.rotation.set(-Math.PI / 4, 0, 0);
  birdGroup.add(rightWing);

  return birdGroup;
};

// Lights
const createLights = () => {
  const lights = [];
  const lightColour = 0xffffff;

  lights.push(new AmbientLight(lightColour, 0.65));

  const directionalLight = new DirectionalLight(lightColour, 0.65);
  directionalLight.castShadow = true;
  directionalLight.shadow.camera.top *= 5;
  directionalLight.shadow.camera.bottom *= 5;
  directionalLight.shadow.camera.left *= 5;
  directionalLight.shadow.camera.right *= 5;
  directionalLight.position.set(20, 30, 10);
  lights.push(directionalLight);

  const fillLight = new DirectionalLight(lightColour, 0.3);
  fillLight.position.set(-20, 20, 20);
  lights.push(fillLight);

  const backLight = new DirectionalLight(lightColour, 0.1);
  backLight.position.set(10, 0, -20);
  lights.push(backLight);

  return lights;
};

// Functions to create AnimationClips
// -- cloud animation clip
const getCloudOpacityClip = () => {
  const tracks = [];
  const opacityTrack = new NumberKeyframeTrack(
    ".material.opacity",
    [0, 3],
    [0.7, 1]
  );
  tracks.push(opacityTrack);

  const cloudsClip = new AnimationClip("cloudOpacityClip", -1, tracks);
  return cloudsClip;
};

const getCloudPositionClip = (clouds) => {
  const tracks = [];
  const position = clouds.position;
  const positionTrack = new VectorKeyframeTrack(
    ".position",
    [0, 2],
    [
      position.x,
      position.y,
      position.z,
      position.x,
      position.y + 0.3,
      position.z,
    ]
  );
  tracks.push(positionTrack);
  return new AnimationClip("cloudPositionClip", -1, tracks);
};

const animateClouds = (clouds, delayStart = 0) => {
  const mixer = new AnimationMixer(clouds);
  const opacityAction = mixer.clipAction(getCloudOpacityClip());
  opacityAction.setLoop(LoopPingPong, Infinity).play();
  const positionAction = mixer.clipAction(getCloudPositionClip(clouds));
  positionAction.setLoop(LoopPingPong, Infinity).startAt(delayStart).play();
  return mixer;
};

// -- bird animation clip
const getGoingAroundClip = (bird) => {
  const position = bird.position.clone();
  const origin = position.clone();
  const steps = 40;
  const angle = -(2 * Math.PI) / steps;
  const rotationMatrix = new Matrix4();
  rotationMatrix.set(
    Math.cos(angle),
    0,
    Math.sin(angle),
    0,
    0,
    1,
    0,
    0,
    -Math.sin(angle),
    0,
    Math.cos(angle),
    0,
    0,
    0,
    0,
    1
  );
  const shift = new Vector3(0, 0, 0);
  const positions = Array(steps)
    .fill()
    .map((_, i) => {
      const newPosition = position.applyMatrix4(rotationMatrix);
      return newPosition.clone().add(shift);
    });
  positions.unshift(origin.add(shift));
  positions[positions.length - 1] = origin.add(shift);
  const times = Array(steps)
    .fill()
    .map((_, i) => i / steps);
  times.push(1);
  const flatPositions = positions
    .map((position) => [position.x, position.y, position.z])
    .flat();
  const positionTrack = new VectorKeyframeTrack(
    ".position",
    times,
    flatPositions
  );
  positionTrack.scale(16);

  return new AnimationClip("birdGoingAround", -1, [positionTrack]);
};

const getBirdSpinningClip = (bird) => {
  const quaternion = bird.quaternion;
  const quaternionTrack = new QuaternionKeyframeTrack(
    ".quaternion",
    [0, 1, 2, 3, 4],
    [
      0,
      0,
      0,
      1,
      0,
      -Math.PI / 4,
      0,
      Math.PI / 4,
      0,
      -1,
      0,
      0,
      0,
      -Math.PI / 4,
      0,
      -Math.PI / 4,
      0,
      0,
      0,
      1,
    ]
  );
  quaternionTrack.scale(4);
  return new AnimationClip("birdSpinning", -1, [quaternionTrack]);
};

const getVerticalMovementClip = (bird) => {
  const position = bird.position;
  const positionTrack = new VectorKeyframeTrack(
    ".position",
    [0, 2],
    [
      position.x,
      position.y,
      position.z,
      position.x,
      position.y + 0.15,
      position.z,
    ]
  );
  return new AnimationClip("birdVerticalMovement", -1, [positionTrack]);
};

const animateBird = (bird) => {
  const mixer = new AnimationMixer(bird);

  const verticalMovementAction = mixer.clipAction(
    getVerticalMovementClip(bird)
  );
  verticalMovementAction.setLoop(LoopPingPong, Infinity).play();

  const flyingAroundAction = mixer.clipAction(getBirdSpinningClip(bird));
  flyingAroundAction.setLoop(LoopRepeat, Infinity).play();

  const goingAroundAction = mixer.clipAction(getGoingAroundClip(bird));
  goingAroundAction.setLoop(LoopRepeat, Infinity).play();
  return mixer;
};

function init() {
  // create a scene, that will hold all our elements such as objects, cameras and lights.
  var scene = new Scene();

  // create a camera, which defines where we're looking at
  const sizes = {
    width: window.innerWidth,
    height: window.innerHeight,
  };
  const aspectRatio = sizes.width / sizes.height,
    fieldOfView = 45,
    nearPlane = 1,
    farPlane = 1000;
  var camera = new PerspectiveCamera(
    fieldOfView,
    aspectRatio,
    nearPlane,
    farPlane
  );

  // create a renderer and set the size
  const canvas = document.getElementById("floating-island");
  var renderer = new WebGLRenderer({
    canvas: canvas,
    alpha: true,
    antialias: true,
  });
  const dpi = window.devicePixelRatio;
  renderer.setSize(sizes.width * dpi, sizes.height * dpi);

  // enable shadows
  renderer.shadowMap.enabled = true;
  renderer.shadowMap.type = PCFSoftShadowMap;

  // add controls to the camera
  const controls = new OrbitControls(camera, renderer.domElement);

  // style the canvas
  canvas.style.width = "${sizes.width}px";
  canvas.style.height = "${sizxes.height}px";

  // tell the camera where to look
  camera.position.set(30, 10, 0);
  camera.lookAt(new Vector3(0, 4, 0));
  controls.update();

  // add elements to the scene
  // -- island
  var island = createIsland();
  scene.add(island);

  // -- stone
  const stone = createStone();
  stone.scale.set(1, 3, 1);
  stone.position.set(-4, 1, 4);
  stone.rotation.set(0, Math.PI / 2, 0);
  island.add(stone);

  const smallStone = createStone();
  smallStone.scale.set(1, 2, 1);
  smallStone.position.set(-3, 1, 5.2);
  island.add(smallStone);

  // -- painting
  const painting = createPainting();
  island.add(painting);
  painting.position.set(-3.3, 1.5, 3.6);
  painting.rotation.set(0, (Math.PI * 2.7) / 4, 0);

  // -- clouds
  const cloud1 = createCloud();
  cloud1.position.set(0, 10, 5);
  cloud1.rotation.set(0, Math.PI / 2, 0);
  scene.add(cloud1);

  const cloud2 = createCloud();
  const cloud2Scale = 0.7;
  cloud2.scale.set(cloud2Scale, cloud2Scale, cloud2Scale);
  cloud2.position.set(2, 8, -1);
  cloud2.rotation.set(0, Math.PI / 2, 0);
  scene.add(cloud2);

  const cloud3 = createCloud();
  cloud3.scale.set(0.8, 0.8, 0.8);
  cloud3.rotation.set(0, Math.PI / 2, 0);
  cloud3.position.set(-2, 9, -4);
  scene.add(cloud3);

  // -- trees
  const tree1 = createTree(4, 2);
  tree1.position.set(3.5, 0, 5.5);
  island.add(tree1);

  const tree2 = createTree(5, 3);
  tree2.position.set(-4, 0, -4);
  island.add(tree2);

  const tree3 = createTree(3, 2);
  tree3.position.set(-4.5, 0, 0);
  island.add(tree3);

  const tree4 = createTree(7, 2);
  tree4.position.set(5, 0, 2);
  island.add(tree4);

  // -- bird
  const bird = createBird();
  bird.scale.set(0.3, 0.3, 0.3);
  bird.position.set(3, 5, -7);

  scene.add(bird);

  // add lights to the scene
  createLights().forEach((light) => {
    scene.add(light);
  });

  // animations
  const mixers = [];
  mixers.push(animateClouds(cloud1, 0));
  mixers.push(animateClouds(cloud2, 1));
  mixers.push(animateClouds(cloud3, 2));
  mixers.push(animateBird(bird));

  const clock = new Clock();
  // function for re-rendering/animating the scene
  function tick() {
    requestAnimationFrame(tick);
    controls.update();
    const delta = clock.getDelta();
    mixers.forEach((mixer) => {
      mixer.update(delta);
    });
    renderer.render(scene, camera);
  }
  tick();
}

init();
