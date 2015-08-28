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
	public float maxVel;

	public bool DEBUGMODE;

	public AudioSource playerSound;

	private bool isActive = true; //false wenn PressSpace benutzt wird


	private Rigidbody2D rg2b;

	private float rot;
	private float acc;



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

	private float VectorAbs(Vector2 a){
		float dis = Mathf.Sqrt (a.x*a.x+a.y*a.y);
		return dis;
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

		// READ INPUTS
		this.rot = -1*Input.GetAxis ("Horizontal");
		this.acc = Input.GetAxis("Vertical");
	}
	void FixedUpdate() {
		// DEBUG

		//Debug.Log ("ORIENTATION: " + rg2b.rotation);
		//Debug.Log ("ANGULAR VELOCITY: " + rg2b.angularVelocity + " | DRAG: " + rg2b.angularDrag);

		// DEBUG
		if (isActive) {
			
			//flames
			
			GameObject flame_l = GameObject.Find("flame_left");
			GameObject flame_r = GameObject.Find ("flame_right");
			Vector3 flamescale = new Vector3(0.6385285f, -0.6385285f, 0.6385285f);


			playerSound.volume = 0.01f;

			// AUSLESEN DER ACHSEN


			// RÜCKWÄRTSFLIEGEN AUSSCHLIESSEN+
			if (!DEBUGMODE){
				if (acc < 0){
					acc = 0;
				}
				acc += 1;
			}
			// FALLS FIRE1 GEDRÜCKT WIRD, BESCHLEUNIGUNG VERDOPPELN
			if (Input.GetButton("Fire1")){
				acc = 2;
				playerSound.volume = 0.05f;
			}

			// FALLS BESCHLEUNIGUNG VORHANDEN, VERGRÖSSERE FLAMME
			if (acc > 1){
				// FLAMME VERGRÖSSERN
				flamescale = new Vector3(1.2f, -1.2f, 1.2f);
			}

			// FALLS FIRE2 GEDRÜCKT WIRD, DRIFT
			if (Input.GetButton("Fire2")){
				// FLAMME AUSBLENDEN
				flamescale = new Vector3(0.0f, 0.0f, 0.0f);
								playerSound.volume = 0.0f;
			}
			// WENN NICHT FIRE2, UPDATE VELOCITY
			else{
				// UPDATE VELOCITY
				if ((VectorAbs(rg2b.velocity) < maxVel)){
					rg2b.velocity += acc * VecProd (GetOrientation (rg2b), new Vector2 (0, 1)) * Time.fixedDeltaTime * gravity;
				}
				rg2b.velocity = rg2b.velocity*0.5f;
			}

			// ADDTORQUE
			if (Mathf.Abs (rg2b.angularVelocity) < maxRotspeed) {
				rg2b.AddTorque (rot * rotSpeed * Time.fixedDeltaTime * rg2b.mass);
			}

			// UPDATE FLAMESCALE
			flame_l.transform.localScale = flamescale;
			flame_r.transform.localScale = flamescale;
			}


			}
	}
