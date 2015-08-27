using UnityEngine;
using System.Collections;
using System;

public class playerController : MonoBehaviour {
	public float jumpHeight;
	public float movementSpeed;
	public float maxRotspeed;
	public float rotSpeed;
	public float gravity;
	public float drag;

	public bool isActive = false;
	
	private bool isDPressed;
	private bool isAPressed;
	private bool isJPressed;
	private bool isHPressed;

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
	}


	// Update is called once per frame
	void Update () {
		if (isActive) {
			if (Input.GetKey ("d")) {
				isDPressed = true;
			} else {
				isDPressed = false;
			}
			if (Input.GetKey ("a")) {
				isAPressed = true;
			} else {
				isAPressed = false;
			}

			if (Input.GetKey ("j")) {
				isJPressed = true;
			} else {
				isJPressed = false;
			}
			if (Input.GetKey ("h")) {
				isHPressed = true;
			} else {
				isHPressed = false;
			}
		}
	}
	void FixedUpdate() {
		// DEBUG

		//Debug.Log ("ORIENTATION: " + rg2b.rotation);
		//Debug.Log ("ANGULAR VELOCITY: " + rg2b.angularVelocity + " | DRAG: " + rg2b.angularDrag);

		// DEBUG
		if (isActive) {
			if (isDPressed) {
				this.transform.position += Vec2ToVec3 (GetOrientation (rg2b) * Time.fixedDeltaTime * movementSpeed);
			} else if (isAPressed) {
				this.transform.position -= Vec2ToVec3 (GetOrientation (rg2b) * Time.fixedDeltaTime * movementSpeed);
			}
			if (isHPressed) {
				if (Mathf.Abs (rg2b.angularVelocity) < maxRotspeed) {
					rg2b.AddTorque (rotSpeed * Time.fixedDeltaTime);
				}
			} else if (isJPressed) {
				if (Mathf.Abs (rg2b.angularVelocity) < maxRotspeed) {
					rg2b.AddTorque (-rotSpeed * Time.fixedDeltaTime);
				}
			}

			// GRAVITATION

			rg2b.velocity = VecProd (GetOrientation (rg2b), new Vector2 (0, 1)) * Time.fixedDeltaTime * gravity;
		}
	}
}
