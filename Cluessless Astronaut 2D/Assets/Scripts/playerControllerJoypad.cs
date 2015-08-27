using UnityEngine;
using System.Collections;
using System;

public class playerControllerJoypad : MonoBehaviour {
	public float jumpHeight;
	public float movementSpeed;
	public float maxRotspeed;
	public float rotSpeed;
	public float gravity;
	public float drag;

	public AudioSource playerSound;

	private bool isActive = true; //false wenn PressSpace benutzt wird


	private Rigidbody2D rg2b;

	private Vector2 VecProd(Vector2 a, Vector2 b){
		return new Vector2(a.x*b.x - a.y*b.y, a.x*b.y + a.y * b.x);
	}

	private Vector2 GetOrientation(Rigidbody2D r){
		return new Vector2 (Mathf.Cos (r.rotation*((float)Math.PI/180.0f)), Mathf.Sin (r.rotation*((float)Math.PI/180.0f)));
	}

	private Vector3 Vec2ToVec3(Vector2 v){
		return new Vector3 (v.x, v.y, 0);
	}

	public void setActive(){
		this.isActive = true;
	}

	// Use this for initialization
	void Start () {
		rg2b = GetComponent<Rigidbody2D> ();
		rg2b.angularDrag = this.drag;

		//sound
		AudioClip jetpack;
		jetpack = (AudioClip)Resources.Load ("jetpack");
		playerSound.clip = jetpack;
		playerSound.loop = true;
	}


	// Update is called once per frame
	void Update () {
		if (!playerSound.isPlaying)
		    { 
			playerSound.Play();
		}

	}
	void FixedUpdate() {
		// DEBUG

		//Debug.Log ("ORIENTATION: " + rg2b.rotation);
		//Debug.Log ("ANGULAR VELOCITY: " + rg2b.angularVelocity + " | DRAG: " + rg2b.angularDrag);

		// DEBUG
		if (isActive) {
			playerSound.volume = 0.01f;

			float rot = -1*Input.GetAxis ("Horizontal");
			float acc = Input.GetAxis("Vertical");
			if (acc < 0){
				acc = 0;
			}
			acc += 1;
			if (Input.GetButton("Fire1")){
				acc = 2;
				playerSound.volume = 0.05f;
			}

			if (Input.GetButton("Fire2")){
				playerSound.volume = 0.0f;
			}
			else{
			rg2b.velocity = acc * VecProd (GetOrientation (rg2b), new Vector2 (0, 1)) * Time.fixedDeltaTime * gravity;
	
			}
			if (Mathf.Abs (rg2b.angularVelocity) < maxRotspeed) {
				rg2b.AddTorque (rot * rotSpeed * Time.fixedDeltaTime);
			}

			// speed

			}
	}
}
